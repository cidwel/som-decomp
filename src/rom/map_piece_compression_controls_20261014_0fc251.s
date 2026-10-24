.setcpu "65816"
.segment "CODE"
.org $C251
map_control_0fc251:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
