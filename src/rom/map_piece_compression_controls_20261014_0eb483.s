.setcpu "65816"
.segment "CODE"
.org $B483
map_control_0eb483:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
