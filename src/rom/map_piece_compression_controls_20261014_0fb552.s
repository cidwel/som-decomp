.setcpu "65816"
.segment "CODE"
.org $B552
map_control_0fb552:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
