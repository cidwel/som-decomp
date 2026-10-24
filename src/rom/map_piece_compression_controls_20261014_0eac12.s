.setcpu "65816"
.segment "CODE"
.org $AC12
map_control_0eac12:
    .byte $EC ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
