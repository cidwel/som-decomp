.setcpu "65816"
.segment "CODE"
.org $52DB
map_control_0e52db:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
