.setcpu "65816"
.segment "CODE"
.org $90E1
map_control_0f90e1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
