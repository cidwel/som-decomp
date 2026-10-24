.setcpu "65816"
.segment "CODE"
.org $F053
map_control_0df053:
    .byte $E1 ; previous-row copy count
