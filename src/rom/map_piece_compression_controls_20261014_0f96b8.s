.setcpu "65816"
.segment "CODE"
.org $96B8
map_control_0f96b8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
