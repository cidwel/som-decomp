.setcpu "65816"
.segment "CODE"
.org $BB75
map_control_0dbb75:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
