.setcpu "65816"
.segment "CODE"
.org $B47D
map_control_0fb47d:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
