; Recovered Secret of Mana USA routine; behaviour documented in docs/native-controller-signal-wait.md.
.setcpu "65816"
.smart
.a8
.i16

wait_for_controller_two_signal_and_unpack_saved_registers = $0040

.segment "CODE"
.org $000C
wait_for_controller_two_signal_long_wrapper:
    jsr wait_for_controller_two_signal_and_unpack_saved_registers
    rtl
