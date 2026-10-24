.setcpu "65816"
.segment "CODE"
.org $100E
map_control_0c100e:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
