.setcpu "65816"
.segment "CODE"
.org $00DF
map_control_0f00df:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
