.setcpu "65816"
.segment "CODE"
.org $A851
map_control_0fa851:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
