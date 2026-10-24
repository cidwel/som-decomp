.setcpu "65816"
.segment "CODE"
.org $200F
map_control_0e200f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
