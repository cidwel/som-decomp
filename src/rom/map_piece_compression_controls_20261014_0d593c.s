.setcpu "65816"
.segment "CODE"
.org $593C
map_control_0d593c:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
