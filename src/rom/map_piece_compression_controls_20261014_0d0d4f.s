.setcpu "65816"
.segment "CODE"
.org $0D4F
map_control_0d0d4f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
