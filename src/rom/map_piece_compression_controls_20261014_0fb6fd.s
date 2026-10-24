.setcpu "65816"
.segment "CODE"
.org $B6FD
map_control_0fb6fd:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
