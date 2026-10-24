.setcpu "65816"
.segment "CODE"
.org $B887
map_control_0db887:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
