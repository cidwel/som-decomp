.setcpu "65816"
.segment "CODE"
.org $5C87
map_control_0e5c87:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
