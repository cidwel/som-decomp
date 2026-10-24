.setcpu "65816"
.segment "CODE"
.org $0D4A
map_control_0d0d4a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
