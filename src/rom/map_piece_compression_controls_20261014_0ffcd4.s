.setcpu "65816"
.segment "CODE"
.org $FCD4
map_control_0ffcd4:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
