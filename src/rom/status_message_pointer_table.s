; Pointers indexed by status bit, traversed from bit15 to bit0.
.setcpu "65816"
.segment "CODE"
.org $5DBB
status_message_pointer_table:
    .word $6116, $6117, $6118, $6124, $6131, $6141, $614E, $615C
    .word $6169, $6178, $6185, $6192, $61A2, $61AE, $61BB, $61C8
