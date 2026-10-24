.setcpu "65816"
.segment "CODE"
.org $80B1
map_control_0f80b1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
