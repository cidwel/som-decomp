.setcpu "65816"
.segment "CODE"
.org $ACE3
map_control_0dace3:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
