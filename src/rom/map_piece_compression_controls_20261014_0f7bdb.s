.setcpu "65816"
.segment "CODE"
.org $7BDB
map_control_0f7bdb:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
