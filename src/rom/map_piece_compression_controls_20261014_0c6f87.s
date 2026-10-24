.setcpu "65816"
.segment "CODE"
.org $6F87
map_control_0c6f87:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
