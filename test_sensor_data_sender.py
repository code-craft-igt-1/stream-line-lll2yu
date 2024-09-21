import unittest
from unittest.mock import mock_open, patch
from io import StringIO
from sensor_data_sender import send_sensor_data


class TestSender(unittest.TestCase):

    @patch('builtins.open', new_callable=mock_open,
           read_data='36.5,72,98\n37.0,75,97')
    @patch('sys.stdout', new_callable=StringIO)
    def test_send_sensor_data(self, mock_stdout, mock_file):
        """
        Test if send_sensor_data reads from a mocked file
          and outputs to console correctly.
        """
        send_sensor_data('sensor_data.csv')

        # Get the actual output written to stdout
        actual_output = mock_stdout.getvalue().strip()

        # Define the expected output
        expected_output = "36.5,72,98\n37.0,75,97"

        # Assert that the actual output matches the expected output
        self.assertEqual(actual_output, expected_output)


if __name__ == '__main__': # pragma: no cover
    unittest.main()
