.setcpu "65816"
.segment "CODE"
.org $D558
map_control_0fd558:
    .byte $EF ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
