.setcpu "65816"
.segment "CODE"
.org $0DC5
map_control_0f0dc5:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
