.setcpu "65816"
.segment "CODE"
.org $7A87
map_control_0e7a87:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
