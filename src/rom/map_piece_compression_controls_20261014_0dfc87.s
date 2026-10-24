.setcpu "65816"
.segment "CODE"
.org $FC87
map_control_0dfc87:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
