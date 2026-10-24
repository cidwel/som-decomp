; Numeric ten-byte idle descriptor selected at 7EA8AA; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $600A
entry_idle = $7EA8BE
cold_idle_task_descriptor:
    .faraddr entry_idle
    .byte $FF ; AAFF task priority
    .word $0000 ; zero repeated-entry word
    .word $0000 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
