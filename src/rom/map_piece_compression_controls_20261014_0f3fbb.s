.setcpu "65816"
.segment "CODE"
.org $3FBB
map_control_0f3fbb:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
