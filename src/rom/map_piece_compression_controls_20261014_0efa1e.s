.setcpu "65816"
.segment "CODE"
.org $FA1E
map_control_0efa1e:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
