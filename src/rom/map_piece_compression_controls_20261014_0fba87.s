.setcpu "65816"
.segment "CODE"
.org $BA87
map_control_0fba87:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
