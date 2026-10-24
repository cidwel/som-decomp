.setcpu "65816"
.segment "CODE"
.org $E80A
map_control_0fe80a:
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
