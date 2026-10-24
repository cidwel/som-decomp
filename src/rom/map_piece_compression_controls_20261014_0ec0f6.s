.setcpu "65816"
.segment "CODE"
.org $C0F6
map_control_0ec0f6:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
