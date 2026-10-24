.setcpu "65816"
.segment "CODE"
.org $A80B
map_control_0fa80b:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
