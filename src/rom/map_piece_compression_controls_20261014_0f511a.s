.setcpu "65816"
.segment "CODE"
.org $511A
map_control_0f511a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
