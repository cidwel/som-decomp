.setcpu "65816"
.segment "CODE"
.org $ECC5
map_control_0eecc5:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $CF ; row-distance/count
