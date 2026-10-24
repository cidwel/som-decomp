.setcpu "65816"
.segment "CODE"
.org $873E
map_control_0d873e:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
