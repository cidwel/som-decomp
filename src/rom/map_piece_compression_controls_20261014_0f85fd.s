.setcpu "65816"
.segment "CODE"
.org $85FD
map_control_0f85fd:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
