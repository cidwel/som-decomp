.setcpu "65816"
.segment "CODE"
.org $52D5
map_control_0d52d5:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
