.setcpu "65816"
.segment "CODE"
.org $961C
map_control_0d961c:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
