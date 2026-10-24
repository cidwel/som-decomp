.setcpu "65816"
.segment "CODE"
.org $167E
map_control_0c167e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6C ; row-distance/count
