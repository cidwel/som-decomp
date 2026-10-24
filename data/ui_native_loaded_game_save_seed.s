.setcpu "65816"
.segment "CODE"
initial_save_numeric_words_and_control_bytes:
    .word $0000, $0000, $0303
    .byte $03, $0F, $0F, $0F
