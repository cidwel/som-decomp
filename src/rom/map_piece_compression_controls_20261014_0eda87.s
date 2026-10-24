.setcpu "65816"
.segment "CODE"
.org $DA87
map_control_0eda87:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
