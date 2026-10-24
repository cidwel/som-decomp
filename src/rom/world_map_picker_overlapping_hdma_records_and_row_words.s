; Native numerical/vector data consumed by the verified picker dependencies.
.setcpu "65816"
.segment "CODE"
.org $A932
world_map_picker_overlapping_hdma_records_and_row_words:
    .byte $24,$00,$12,$90,$00,$12,$77,$20,$12,$90,$10,$12,$00,$EC,$EC,$EB
    .byte $EB,$EA,$EA,$E9,$E9,$E8,$E7,$E6,$E5,$E4,$E3,$E2,$E1,$E1,$E2,$E3
    .byte $E4,$E5,$E6,$E7,$E8,$E9,$E9,$EA,$EA,$EB,$EB,$EC,$EC,$E0,$00
; Mirrored geometry-row words begin at C0A961; earlier overlapping reads share bytes.
    .word $0100,$0100,$0100,$0100,$0101,$0101,$0101,$0102
    .word $0102,$0103,$0103,$0104,$0105,$0106,$0106,$0108
    .word $0109,$010A,$010B,$010C,$010E,$010F,$0111,$0112
    .word $0114,$0116,$0118,$011A,$011D,$011F,$0122,$0125
    .word $0128,$012B,$012E,$0132,$0136,$013A,$013F,$0143
    .word $0149,$014E,$0154,$015A,$0161,$0169,$0171,$0179
    .word $0184,$018F,$019B,$01A8,$01B9,$01CB,$01DF,$01F7
    .word $0213,$0236,$025F,$0298,$02E5,$0350,$0411,$05BF
