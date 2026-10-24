.setcpu "65816"
.segment "CODE"
.org $6BE4
map_control_0e6be4:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
