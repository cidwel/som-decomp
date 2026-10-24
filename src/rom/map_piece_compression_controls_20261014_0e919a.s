.setcpu "65816"
.segment "CODE"
.org $919A
map_control_0e919a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
