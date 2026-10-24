.setcpu "65816"
.segment "CODE"
.org $5935
map_control_0d5935:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
