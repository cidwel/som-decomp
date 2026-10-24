.setcpu "65816"
.segment "CODE"
.org $AC74
map_control_0eac74:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
