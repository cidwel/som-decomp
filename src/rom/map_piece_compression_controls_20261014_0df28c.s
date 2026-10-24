.setcpu "65816"
.segment "CODE"
.org $F28C
map_control_0df28c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
