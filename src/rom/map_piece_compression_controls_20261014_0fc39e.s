.setcpu "65816"
.segment "CODE"
.org $C39E
map_control_0fc39e:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
