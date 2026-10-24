.setcpu "65816"
.segment "CODE"
.org $A965
map_control_0ea965:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
