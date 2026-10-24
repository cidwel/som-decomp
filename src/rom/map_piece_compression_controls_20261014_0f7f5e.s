.setcpu "65816"
.segment "CODE"
.org $7F5E
map_control_0f7f5e:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
