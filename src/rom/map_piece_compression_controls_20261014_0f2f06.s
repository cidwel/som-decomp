.setcpu "65816"
.segment "CODE"
.org $2F06
map_control_0f2f06:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
